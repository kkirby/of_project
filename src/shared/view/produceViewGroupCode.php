<?php
$viewrectTypes = [
	['PX',['PX','Pixel']],
	['VW',['VW','OfViewportWidth']],
	['VH',['VH','OfViewportHeight']],
	['CW',['CW','OfContainerWidth']],
	['CH',['CH','OfContainerHeight']],
	['PRCT',['PR','Percent']],
];
$viewrectPositions = [
	['top','Top'],
	['right','Right'],
	['bottom','Bottom'],
	['left','Left'],
	['width','Width'],
	['height','Height']
];

$headers = [];
$body = [];

$headers2 = [];
$body2 = [];
foreach($viewrectPositions as $positionInfo){
	list($positionProperty,$positionSetterName) = $positionInfo;
	foreach($viewrectTypes as $typeInfo){
		list($typeUnit,$typeSetterNames) = $typeInfo;
		$rootSetterName = null;
		foreach($typeSetterNames as $k => $typeSettereName){
			$setterName = $positionSetterName.$typeSettereName;
			$headers[] = "ViewRect& set${setterName}(double value);";
			if($k === 0){
				$rootSetterName = $setterName;
				if($typeUnit === 'PRCT'){
					$tmp = $positionSetterName;
					if($tmp == 'Top' || $tmp == 'Bottom'){
						$tmp = 'Height';
					}
					else if($tmp == 'Left' || $tmp == 'Right'){
						$tmp  = 'Width';
					}
					$body[] = "ViewRect& ViewRect::set${setterName}(double value){\n".
						"\treturn set${positionSetterName}OfContainer${tmp}(value);\n".
					"}";
				}
				else {
					$body[] = "ViewRect& ViewRect::set${setterName}(double value){\n".
						"\t${positionProperty}.unit = ViewRect::Size::Unit::${typeUnit};\n".
						"\t${positionProperty}.value = value;\n".
						"\t${positionProperty}.hasValue = true;\n".
						"\treturn *this;\n".
					"}";
				}
			}
			else {
				$body[] = "ViewRect& ViewRect::set${setterName}(double value){\n".
					"\treturn set${rootSetterName}(value);\n".
				"}";
			}
		}
		if($typeUnit === 'PX'){
			$headers[] = "ViewRect& set${positionSetterName}(double value);";
			$body[] = "ViewRect& ViewRect::set${positionSetterName}(double value){\n".
				"\treturn set${positionSetterName}PX(value);\n".
			"}";
		}
	}
	$headers2[] = "double get${positionSetterName}Value();";
	$headers2[] = "ViewRect::Size::Unit get${positionSetterName}Unit();";
	
	$headers2[] = "ViewRect& unset${positionSetterName}();";
	$headers2[] = "ViewRect& set${positionSetterName}();";
	
	$body2[] = "double ViewRect::get${positionSetterName}Value(){\n".
		"\treturn ${positionProperty}.hasValue ? ${positionProperty}.value : 0;\n".
	"}";
	$body2[] = "ViewRect::Size::Unit ViewRect::get${positionSetterName}Unit(){\n".
		"\treturn ${positionProperty}.unit;\n".
	"}";
	
	$body2[] = "ViewRect& ViewRect::unset${positionSetterName}(){\n".
		"\t${positionProperty}.hasValue = false;\n".
		"\treturn *this;\n".
	"}";
	$body2[] = "ViewRect& ViewRect::set${positionSetterName}(){\n".
		"\treturn unset${positionSetterName}();\n".
	"}";
}

function updateContents($contents,$replacement){
	$contents = explode("\n",$contents);
	$output = [];
	$inRemoval = false;
	$space = "";
	foreach($contents as $line){
		if($inRemoval == false){
			if(trim($line) == '//--- BEGIN '.basename(__FILE__)){
				$inRemoval = true;
				preg_match('/^(\s*)/',$line,$spaces);
				$space = $spaces[1];
				$output[] = $line;
			}
			else {
				$output[] = $line;
			}
		}
		else {
			if(trim($line) == '//--- END '.basename(__FILE__)){
				$replacement = explode("\n",$replacement);
				foreach($replacement as $replacementLine){
					$output[] = $space . $replacementLine;
				}
				$output[] = $line;
				$inRemoval = false;
			}
		}
	}
	return implode("\n",$output);
}

$headersOut = implode("\n",$headers) . "\n\n" . implode("\n",$headers2) ;
$bodyOut = implode("\n\n",$body) . "\n\n" . implode("\n\n",$body2);


$headerContent = file_get_contents(__DIR__ . '/ViewRect.h');
file_put_contents(__DIR__.'/ViewRect.h.bk',$headerContent);
file_put_contents(__DIR__.'/ViewRect.h',updateContents($headerContent,$headersOut));

$bodyContent = file_get_contents(__DIR__ . '/ViewRect.cpp');
file_put_contents(__DIR__.'/ViewRect.cpp.bk',$headerContent);
file_put_contents(__DIR__.'/ViewRect.cpp',updateContents($bodyContent,$bodyOut));

?>
