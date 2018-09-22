//----------------------------------------------------------------------------
//
//  Copyright (C) 2004-2018 by EMGU Corporation. All rights reserved.
//
//----------------------------------------------------------------------------

#pragma once
#ifndef EMGU_FEATURES2D_C_H
#define EMGU_FEATURES2D_C_H

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/features2d/features2d.hpp"
//#include "opencv2/legacy/compat.hpp"
#include "vectors_c.h"

//ORB
CVAPI(cv::ORB*) cveOrbDetectorCreate(int numberOfFeatures, float scaleFactor, int nLevels, int edgeThreshold, int firstLevel, int WTA_K, int scoreType, int patchSize, int fastThreshold, cv::Feature2D** feature2D, cv::Ptr<cv::ORB>** sharedPtr);
CVAPI(void) cveOrbDetectorRelease(cv::ORB** detector, cv::Ptr<cv::ORB>** sharedPtr);

//Brisk
CVAPI(cv::BRISK*) cveBriskCreate(int thresh, int octaves, float patternScale, cv::Feature2D** feature2D, cv::Ptr<cv::BRISK>** sharedPtr);
CVAPI(void) cveBriskRelease(cv::BRISK** detector, cv::Ptr<cv::BRISK>** sharedPtr);

//FAST algorithm
CVAPI(cv::FastFeatureDetector*) cveFASTGetFeatureDetector(int threshold, bool nonmax_supression, int type, cv::Feature2D** feature2D, cv::Ptr<cv::FastFeatureDetector>** sharedPtr);
CVAPI(void) cveFASTFeatureDetectorRelease(cv::FastFeatureDetector** detector, cv::Ptr<cv::FastFeatureDetector>** sharedPtr);

//GFTT
CVAPI(cv::GFTTDetector*) cveGFTTDetectorCreate(int maxCorners, double qualityLevel, double minDistance, int blockSize, bool useHarrisDetector, double k, cv::Feature2D** feature2D, cv::Ptr<cv::GFTTDetector>** sharedPtr);
CVAPI(void) cveGFTTDetectorRelease(cv::GFTTDetector** detector, cv::Ptr<cv::GFTTDetector>** sharedPtr);

// MSER detector
CVAPI(cv::MSER*) cveMserGetFeatureDetector(
	int delta,
	int minArea,
	int maxArea,
	double maxVariation,
	double minDiversity,
	int maxEvolution,
	double areaThreshold,
	double minMargin,
	int edgeBlurSize,
	cv::Feature2D** feature2D,
	cv::Ptr<cv::MSER>** sharedPtr);
CVAPI(void) cveMserDetectRegions(
	cv::MSER* mserPtr,
	cv::_InputArray* image,
	std::vector< std::vector<cv::Point> >* msers,
	std::vector< cv::Rect >* bboxes);
CVAPI(void) cveMserFeatureDetectorRelease(cv::MSER** mser, cv::Ptr<cv::MSER>** sharedPtr);


// SimpleBlobDetector
CVAPI(cv::SimpleBlobDetector*) cveSimpleBlobDetectorCreate(cv::Feature2D** feature2DPtr, cv::Ptr<cv::SimpleBlobDetector>** sharedPtr);
CVAPI(cv::SimpleBlobDetector*) cveSimpleBlobDetectorCreateWithParams(cv::Feature2D** feature2DPtr, cv::SimpleBlobDetector::Params* params, cv::Ptr<cv::SimpleBlobDetector>** sharedPtr);
CVAPI(void) cveSimpleBlobDetectorRelease(cv::SimpleBlobDetector** detector, cv::Ptr<cv::SimpleBlobDetector>** sharedPtr);
CVAPI(cv::SimpleBlobDetector::Params*) cveSimpleBlobDetectorParamsCreate();
CVAPI(void) cveSimpleBlobDetectorParamsRelease(cv::SimpleBlobDetector::Params** params);

// Draw keypoints.
CVAPI(void) drawKeypoints(
	cv::_InputArray* image,
	const std::vector<cv::KeyPoint>* keypoints,
	cv::_InputOutputArray* outImage,
	const CvScalar* color,
	int flags);

// Draws matches of keypints from two images on output image.
CVAPI(void) drawMatchedFeatures(
	cv::_InputArray* img1, const std::vector<cv::KeyPoint>* keypoints1,
	cv::_InputArray* img2, const std::vector<cv::KeyPoint>* keypoints2,
	std::vector< std::vector< cv::DMatch > >* matches,
	cv::_InputOutputArray* outImg,
	const CvScalar* matchColor, const CvScalar* singlePointColor,
	cv::_InputArray* matchesMask,
	int flags);

//DescriptorMatcher
CVAPI(void) cveDescriptorMatcherAdd(cv::DescriptorMatcher* matcher, cv::_InputArray* trainDescriptors);

CVAPI(void) cveDescriptorMatcherKnnMatch1(
	cv::DescriptorMatcher* matcher,
	cv::_InputArray* queryDescriptors,
	cv::_InputArray* trainDescriptors,
	std::vector< std::vector< cv::DMatch > >* matches,
	int k,
	cv::_InputArray* mask,
	bool compactResult);

CVAPI(void) cveDescriptorMatcherKnnMatch2(
	cv::DescriptorMatcher* matcher,
	cv::_InputArray* queryDescriptors,
	std::vector< std::vector< cv::DMatch > >* matches,
	int k,
	cv::_InputArray* mask,
	bool compactResult);

CVAPI(cv::Algorithm*) cveDescriptorMatcherGetAlgorithm(cv::DescriptorMatcher* matcher);

CVAPI(void) cveDescriptorMatcherClear(cv::DescriptorMatcher* matcher);
CVAPI(bool) cveDescriptorMatcherEmpty(cv::DescriptorMatcher* matcher);
CVAPI(bool) cveDescriptorMatcherIsMaskSupported(cv::DescriptorMatcher* matcher);
CVAPI(void) cveDescriptorMatcherTrain(cv::DescriptorMatcher* matcher);
CVAPI(void) cveDescriptorMatcherMatch1(
	cv::DescriptorMatcher* matcher,
	cv::_InputArray* queryDescriptors,
	cv::_InputArray* trainDescriptors,
	std::vector< cv::DMatch >* matches,
	cv::_InputArray* mask);
CVAPI(void) cveDescriptorMatcherMatch2(
	cv::DescriptorMatcher* matcher,
	cv::_InputArray* queryDescriptors,
	std::vector< cv::DMatch >* matches,
	cv::_InputArray* masks);

CVAPI(void) cveDescriptorMatcherRadiusMatch1(
	cv::DescriptorMatcher* matcher,
	cv::_InputArray* queryDescriptors,
	cv::_InputArray* trainDescriptors,
	std::vector< std::vector<cv::DMatch> >* matches,
	float maxDistance,
	cv::_InputArray* mask,
	bool compactResult);
CVAPI(void) cveDescriptorMatcherRadiusMatch2(
	cv::DescriptorMatcher* matcher,
	cv::_InputArray* queryDescriptors,
	std::vector< std::vector<cv::DMatch> >* matches,
	float maxDistance,
	cv::_InputArray* masks,
	bool compactResult);


//BruteForceMatcher
CVAPI(cv::BFMatcher*) cveBFMatcherCreate(int distanceType, bool crossCheck, cv::DescriptorMatcher** m);
CVAPI(void) cveBFMatcherRelease(cv::BFMatcher** matcher);

//FlannBasedMatcher
CVAPI(cv::FlannBasedMatcher*) cveFlannBasedMatcherCreate(cv::flann::IndexParams* indexParams, cv::flann::SearchParams* searchParams, cv::DescriptorMatcher** m);
CVAPI(void) cveFlannBasedMatcherRelease(cv::FlannBasedMatcher** matcher);

//2D Tracker
CVAPI(int) voteForSizeAndOrientation(std::vector<cv::KeyPoint>* modelKeyPoints, std::vector<cv::KeyPoint>* observedKeyPoints, std::vector< std::vector< cv::DMatch > >* matches, cv::Mat* mask, double scaleIncrement, int rotationBins);

//Feature2D
CVAPI(void) CvFeature2DDetectAndCompute(cv::Feature2D* feature2D, cv::_InputArray* image, cv::_InputArray* mask, std::vector<cv::KeyPoint>* keypoints, cv::_OutputArray* descriptors, bool useProvidedKeyPoints);
CVAPI(void) CvFeature2DDetect(cv::Feature2D* feature2D, cv::_InputArray* image, std::vector<cv::KeyPoint>* keypoints, cv::_InputArray* mask);
CVAPI(void) CvFeature2DCompute(cv::Feature2D* feature2D, cv::_InputArray* image, std::vector<cv::KeyPoint>* keypoints, cv::_OutputArray* descriptors);
CVAPI(int) CvFeature2DGetDescriptorSize(cv::Feature2D* feature2D);
CVAPI(cv::Algorithm*) CvFeature2DGetAlgorithm(cv::Feature2D* feature2D);

//BowKMeansTrainer
CVAPI(cv::BOWKMeansTrainer*) CvBOWKMeansTrainerCreate(int clusterCount, const CvTermCriteria* termcrit, int attempts, int flags);
CVAPI(void) CvBOWKMeansTrainerRelease(cv::BOWKMeansTrainer** trainer);
CVAPI(int) CvBOWKMeansTrainerGetDescriptorCount(cv::BOWKMeansTrainer* trainer);
CVAPI(void) CvBOWKMeansTrainerAdd(cv::BOWKMeansTrainer* trainer, cv::Mat* descriptors);
CVAPI(void) CvBOWKMeansTrainerCluster(cv::BOWKMeansTrainer* trainer, cv::_OutputArray* cluster);

//BOWImgDescriptorExtractor
CVAPI(cv::BOWImgDescriptorExtractor*) CvBOWImgDescriptorExtractorCreate(cv::Feature2D* descriptorExtractor, cv::DescriptorMatcher* descriptorMatcher);
CVAPI(void) CvBOWImgDescriptorExtractorRelease(cv::BOWImgDescriptorExtractor** descriptorExtractor);
CVAPI(void) CvBOWImgDescriptorExtractorSetVocabulary(cv::BOWImgDescriptorExtractor* bowImgDescriptorExtractor, cv::Mat* vocabulary);
CVAPI(void) CvBOWImgDescriptorExtractorCompute(cv::BOWImgDescriptorExtractor* bowImgDescriptorExtractor, cv::_InputArray* image, std::vector<cv::KeyPoint>* keypoints, cv::Mat* imgDescriptor);

//KAZEDetector
CVAPI(cv::KAZE*) cveKAZEDetectorCreate(
	bool extended, bool upright, float threshold,
	int octaves, int sublevels, int diffusivity,
	cv::Feature2D** feature2D, cv::Ptr<cv::KAZE>** sharedPtr);
CVAPI(void) cveKAZEDetectorRelease(cv::KAZE** detector, cv::Ptr<cv::KAZE>** sharedPtr);

//AKAZEDetector
CVAPI(cv::AKAZE*) cveAKAZEDetectorCreate(
	int descriptorType, int descriptorSize, int descriptorChannels,
	float threshold, int octaves, int sublevels, int diffusivity,
	cv::Feature2D** feature2D, cv::Ptr<cv::AKAZE>** sharedPtr);
CVAPI(void) cveAKAZEDetectorRelease(cv::AKAZE** detector, cv::Ptr<cv::AKAZE>** sharedPtr);

//Agast
CVAPI(cv::AgastFeatureDetector*) cveAgastFeatureDetectorCreate(int threshold, bool nonmaxSuppression, int type, cv::Feature2D** feature2D, cv::Ptr<cv::AgastFeatureDetector>** sharedPtr);
CVAPI(void) cveAgastFeatureDetectorRelease(cv::AgastFeatureDetector** detector, cv::Ptr<cv::AgastFeatureDetector>** sharedPtr);

#endif