// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyProgressBar.generated.h"

class UHorizontalBox;
class UTextBlock;
class UProgressBar;
class USizeBox;
/**
 *
 */


UCLASS()
class FPS1_API UMyProgressBar : public UUserWidget
{
	GENERATED_BODY()

public:
	// Expose text property as an instance-editable variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Widget")
	FText DisplayText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Widget")
	FLinearColor ProgressBarColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Widget")
	float MyPercent;

	// Function to update the text dynamically
	UFUNCTION(BlueprintCallable, Category = "Custom Widget")
	void SetText(FText NewText);

	UFUNCTION(BlueprintCallable, Category = "Custom Widget")
	void SetProgressBarColor(FLinearColor NewColor);

	// Reference to the internal TextBlock (bind it in Blueprint)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UHorizontalBox> HorizontalBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UTextBlock> TextBlock;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UProgressBar> ProgressBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<USizeBox> TextSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<USizeBox> ProgressBarSize;

protected:
	virtual void NativeConstruct() override;
	virtual void SynchronizeProperties() override;
};
