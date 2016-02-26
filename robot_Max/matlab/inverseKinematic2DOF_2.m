function [PHI] = inverseKinematic2DOF_2(A, L1,L2, L3)
%inverseKinematic2DOF_2 calculates inverse kinematic of biped's leg
%
%   author: Mateusz Percinski
%   date:   2016-02-02
%
%   coordinate system in center of foot
%   leg - 2 degrees of freedom 
%   (3 joints, but foot ist still parallel to ground
%
%   picture inverseKinematic2DOF_2.png shows
%   coordinate system and how angles are measured 
%
%   INPUTS: A  - matrix 2x1 - coordinates of hip
%           L1 - matrix 1x1 - length of thigh
%           L2 - matrix 1x1 - length of shin
%           L3 - matrix 1x1 - length of foot
%
%   OUTPUTS: PHI - matrix 3x1 - angles in joints of leg

S(1)=-A(1);
S(2)=A(2);
PHI = inverseKinematic2DOF_1(S, L1, L2, L3);

end

