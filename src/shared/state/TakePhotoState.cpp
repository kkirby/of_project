#include "TakePhotoState.h"

#include "ViewBuilder.h"
#include "RootView.h"
#include "CameraImageView.h"
#include "TextureView.h"
#include "ButtonView.h"
#include "ImageView.h"
#include "ColoredRect.h"

TakePhotoState::TakePhotoState(){}

void TakePhotoState::setup(){
	overlay.load("overlay2.png");
	
	view = ViewBuilder<RootView>({
		{"fill",""},
		{"id","root"}
	})->addChild(
		ViewBuilder<CameraImageView>(
			{{"fill",""}},
			&overlay
		)
	)->addChild(
		ViewBuilder<ImageView>(
			{
				{"width","10vw"},
				{"height","10vw"},
				{"right","20px"},
				{"top","5vh"}
			},
			"take_photo.png"
		)
	);
	/*->addChild(
		ViewBuilder<ButtonView>(
			{
				{"id","Button"},
				{"right","10px"},
				{"top","10px"},
				{"width","341px"},
				{"height","341px"}
			},
			ViewBuilder<ImageView>(
				{
					{"fill",""}
				},
				"btn.png"
			),
			ViewBuilder<ImageView>(
				{
					{"fill",""}
				},
				"btn_down.png"
			),
			[](){
				ofLogVerbose("ClickAction") << "Clicked!";
			}
		)
	)->addChild(
		ViewBuilder<ColoredRect>(
			{
				{"id","Colored"},
				{"top","10px"},
				{"left","10px"},
				{"width","100px"},
				{"height","100px"}
			},
			10,10,10
		)
	)->addChild(
		ViewBuilder<ColoredRect>(
			{
				{"top","130px"},
				{"left","130px"},
				{"width","100px"},
				{"height","100px"}
			},
			20,20,20	
		)
	)*/;
}
string TakePhotoState::getName(){
	return "takePhotoState";
}