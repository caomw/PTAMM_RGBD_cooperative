/*
 * Params.cpp
 *
 *  Created on: May 8, 2013
 *      Author: Giuseppe Loianno
 */

#include <ParamsPTAMM.h>
#include<iostream>
using namespace std;
//ParamsAccess params_obj;

PTAMM_RGBD_cooperative::PtammParamsConfig* ParamsAccess::varParams;
FixParams* ParamsAccess::fixParams;

void FixParams::readFixParams()
{
  ros::NodeHandle nh("~");

  // kill program, if we don't have a camera calibration
  bool have_calibration = true;
  have_calibration = have_calibration && nh.getParam("fx_rgb", fx_rgb);
  have_calibration = have_calibration && nh.getParam("fy_rgb", fy_rgb);
  have_calibration = have_calibration && nh.getParam("cx_rgb", cx_rgb);
  have_calibration = have_calibration && nh.getParam("cy_rgb", cy_rgb);
cout<<fx_rgb<<endl;
cout<<fy_rgb<<endl;
cout<<cx_rgb<<endl;
cout<<cy_rgb<<endl;






  if (!have_calibration)
  {
    ROS_ERROR("Camera calibration is missing!");
//    ROS_BREAK();
  }
  nh.param<int>("DR", DR, 80);
  nh.param<int>("DC", DC, 80);
  nh.param<int>("STEP_R_MAX", STEP_R_MAX, 40);
  nh.param<int>("STEP_R_MIN", STEP_R_MIN, 20);
  nh.param<int>("STEP_C_MAX", STEP_C_MAX, 40);
  nh.param<int>("STEP_C_MAX", STEP_C_MIN, 20);
  nh.param<int>("Z_MAX", Z_MAX, 5.0);
  nh.param<int>("Z_MIN", Z_MIN, 0.5);

  nh.param("image_width", image_width, 320);
  nh.param("image_height", image_height, 240);
  nh.param("ARBuffer_width", ARBuffer_width, 1200);
  nh.param("ARBuffer_height", ARBuffer_height, 900);
  nh.param("BundleMEstimator", BundleMEstimator, std::string("Tukey"));
  nh.param("TrackerMEstimator", TrackerMEstimator, std::string("Tukey"));
  nh.param("MinTukeySigma", MinTukeySigma, 0.4);
  nh.param("CandidateMinShiTomasiScore", CandidateMinShiTomasiScore, 70);

  //nh.param("Calibrator_BlurSigma", Calibrator_BlurSigma, 1.0);
  //nh.param("Calibrator_MeanGate", Calibrator_MeanGate, 10.0);
  //nh.param("Calibrator_MinCornersForGrabbedImage", Calibrator_MinCornersForGrabbedImage, 20);
  //nh.param("Calibrator_Optimize", Calibrator_Optimize, false);
  //nh.param("Calibrator_Show", Calibrator_Show, false);
  //nh.param("Calibrator_NoDistortion", Calibrator_NoDistortion, false);
 // nh.param("CameraCalibrator_MaxStepDistFraction", CameraCalibrator_MaxStepDistFraction, 0.3);
  //nh.param("CameraCalibrator_CornerPatchSize", CameraCalibrator_CornerPatchSize, 20);
  nh.param("mgvnEnabled", mgvnEnabled, true);
  nh.param("mgvnMenuItemWidth", mgvnMenuItemWidth, 90);
  nh.param("mgvnMenuTextOffset", mgvnMenuTextOffset, 20);
  nh.param("InitLevel", InitLevel, 1);
  nh.param("parent_frame", parent_frame, std::string("world"));
  nh.param("gui", gui, false);
}
;
