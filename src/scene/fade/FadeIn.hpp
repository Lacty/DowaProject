
#pragma once

#include "FadeBase.hpp"


class FadeIn :public FadeBase {

private:

	std::function<void()>fade;

	void fullScreenFade(
		int endTime = 2,
		ci::Color color = ci::Color::black(),
		bool isUseEasing = false);

	void circleScalingFade(
		int endTime = 2,
		ci::Color color = ci::Color::black(),
		bool isUseEasing = false);

	void veilDownFade(
		int endTime = 2,
		ci::Color color = ci::Color::black(),
		bool isUseEasing = false);

	void fromLeftCurtainFade(
		int endTime = 2,
		ci::Color color = ci::Color::black(),
		bool isUseEasing = false);

	void fromRightCurtainFade(
		int endTime = 2,
		ci::Color color = ci::Color::black(),
		bool isUseEasing = false);

	void centerCurtainFade(
		int endTime = 2,
		ci::Color color = ci::Color::black(),
		bool isUseEasing = false);

	void pinHoleFade(
		int endTime = 2, float space = 0.0f, const int slices = 12,
		ci::Color color = ci::Color::black(), bool isUseEasing = false);

public:

	FadeIn();

	void setType(
		FadeType,
		int time = 2,
		ci::Color color = ci::Color::black(),
		bool isUseEasing = false
		);

	bool getIsEnd();

	void draw();

};

