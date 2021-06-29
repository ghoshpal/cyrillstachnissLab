

#include "../includes/3DCS_01.h"

#include <cmath>
#include <vector>

using std::vector;

CS3D::point3d CS3D ::rotation(CS3D::rotationAxis axis, const float theta_deg) {
  CS3D::point3d ans;
  if (axis == CS3D ::rotationAxis::xaxis) {
    vector<vector<float> > rotationMat_xaxis = {
        {1, 0, 0},
        {0, std::cos(theta_deg), -std::sin(theta_deg)},
        {0, std::sin(theta_deg), std::cos(theta_deg)}};

  } else if (axis == CS3D::rotationAxis::yaxis) {
    vector<vector<float> > rotationMat_yaxis = {
        {std::cos(theta_deg), 0, std::sin(theta_deg)},
        {0, 1, 0},
        {-std::sin(theta_deg), 0, std::cos(theta_deg)}};
  }

  else if (axis == CS3D::rotationAxis::zaxis) {
    vector<vector<float> > rotationMat_yaxis = {
        {std::cos(theta_deg), -std::sin(theta_deg), 0},
        {std::sin(theta_deg), std::cos(theta_deg), 0},
        {0, 0, 1}};
  } else {
    // Nothing can be done. Check axis
  }
  return ans;
}
