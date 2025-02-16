// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProgressBar.h"
#include "Components/HorizontalBox.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Components/SizeBox.h"

void UMyProgressBar::NativeConstruct()
{
	Super::NativeConstruct();

	// Apply the initialization when the widget is created
	if (HorizontalBox)
	{
		if (TextBlock)
		{
			if (TextSize)
			{
				HorizontalBox->AddChildToHorizontalBox(TextSize);
				TextSize->AddChild(TextBlock);
			}
			TextBlock->SetText(DisplayText);
		}
		if (ProgressBar)
		{
			if (ProgressBarSize)
			{
				HorizontalBox->AddChildToHorizontalBox(ProgressBarSize);
				ProgressBarSize->AddChild(ProgressBar);
			}
			ProgressBar->SetFillColorAndOpacity(ProgressBarColor);
		}
	}
}

void UMyProgressBar::SetText(FText NewText)
{
	DisplayText = NewText;

	if (TextBlock)
	{
		TextBlock->SetText(DisplayText);
	}
}


void UMyProgressBar::SetProgressBarColor(FLinearColor NewColor)
{
	ProgressBarColor = NewColor;

	if (ProgressBar)
	{
		ProgressBar->SetFillColorAndOpacity(ProgressBarColor);
	}
}

void UMyProgressBar::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	SetText(DisplayText);
	SetProgressBarColor(ProgressBarColor);
}


