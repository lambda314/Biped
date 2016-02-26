function [ PHI_R, PHI_L ] = inverseKinematic4DOF_1( S_R, S_L, L1, L2, L3)
%inverseKinematic4DOF calculates inverse kinematic of biped
%
%   author: Mateusz Percinski
%   date:   2016-02-02
%
%   each leg - 2 degrees of freedom 
%   (3 joints, but feet are still parallel to ground
%
%   picture inverseKinematic4DOF.png shows how angles are measured
%
%   INPUTS: S_R - matrix 2x1 - coordinates of center of right foot
%           S_L - matrix 2x1 - coordinates of center of left foot
%           L1  - matrix 1x1 - length of thigh
%           L2	- matrix 1x1 - length of shin
%           L3	- matrix 1x1 - length of foot
%
%   OUTPUTS: PHI_R - matrix 3x1 - angles in joints of right leg
%            PHI_L - matrix 3x1 - angles in joints of left leg

%% right leg
PHI_R=inverseKinematic2DOF_1(S_R,L1,L2,L3);

%% left leg
PHI_L=inverseKinematic2DOF_1(S_L,L1,L2,L3);

end

