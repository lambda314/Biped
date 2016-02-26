function PHI = inverseKinematic2DOF_1(S, L1,L2, L3)
%inverseKinematic2DOF_1 calculates inverse kinematic of biped's leg
%
%   author: Mateusz Percinski
%   date:   2016-02-02
%
%   coordinate system in hip
%   leg - 2 degrees of freedom 
%   (3 joints, but foot ist still parallel to ground
%
%   picture inverseKinematic2DOF_1.png shows
%   coordinate system and how angles are measured 
%
%   INPUTS: S  - matrix 2x1 - coordinates of hip
%           L1 - matrix 1x1 - length of thigh
%           L2 - matrix 1x1 - length of shin
%           L3 - matrix 1x1 - length of foot
%
%   OUTPUTS: PHI - matrix 3x1 - angles in joints of leg

    PHI(2)=acos(((S(1)-L3/2)^2+S(2)^2-L1^2-L2^2)/(2*L1*L2));
    PHI(1)=asin(L2*sin(PHI(2))/(sqrt((S(1)-L3/2)^2+S(2)^2)))+atan2((S(1)-L3/2),S(2));
    PHI(3)=pi/2-(pi/2-PHI(1)); 

end