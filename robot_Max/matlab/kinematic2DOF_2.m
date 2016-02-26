function [A] = kinematic2DOF_2(PHI, L1, L2, L3)
%kinematic2DOF_2 calculates kinematic of biped's leg
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
%   INPUTS: PHI - matrix 3x1 - angles in joints of leg
%           L1 - matrix 1x1 - length of thigh
%           L2 - matrix 1x1 - length of shin
%           L3 - matrix 1x1 - length of foot
%
%   OUTPUTS: A  - matrix 2x1 - coordinates of hip

A =[-(L1*sin(PHI(1))-L2*sin(PHI(2)-PHI(1))+L3/2) 
    -(-L1*cos(PHI(1))-L2*cos(PHI(2)-PHI(1)))]';

end