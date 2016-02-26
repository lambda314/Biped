function drawLeg2DOF_2(PHI, L1, L2, L3)
%drawLeg2DOF_2 draws scheme with leg configuration
%
%   author: Mateusz Percinski
%   date:   2016-02-02
%
%   Coordinate system in center of foot
%
%   INPUTS: PHI - matrix 3x1 - angles in joints of leg
%           L1    - matrix 1x1 - length of thigh
%           L2    - matrix 1x1 - length of shin
%           L3    - matrix 1x1 - length of foot
%

%% POINTS DEFINITIONS FOR SCHEME
%% left leg
S=[0 0]';
D=[L3/2 0]';
C=[-L3/2 0]';
B=C+[L2*cos(pi-PHI(2)-(pi/2-PHI(1))) L2*sin(pi-PHI(2)-(pi/2-PHI(1)))]';
A=B+[-L1*sin(PHI(1)) L1*cos(PHI(1))]';
% P1_a=[L1*sin(PHI_R(1)) -L1*cos(PHI_R(1))];
% P2_a=[L1*sin(PHI_R(1))-L2*sin(PHI_R(2)-PHI_R(1)) -L1*cos(PHI_R(1))-L2*cos(PHI_R(2)-PHI_R(1))];
% P3_a=[L1*sin(PHI_R(1))-L2*sin(PHI_R(2)-PHI_R(1))-L3*cos(PHI_R(3)+pi-PHI_R(1)) -L1*cos(PHI_R(1))-L2*cos(PHI_R(2)-PHI_R(1))+L3*sin(PHI_R(3)+pi-PHI_R(1))];

%% DRAWING SCHEME %
%% left leg (blue)
line([D(1) C(1)],[D(2) C(2)],'Linewidth',3) %line of foot
line([C(1) B(1)],[C(2) B(2)],'Linewidth',3) %line of shin
line([B(1) A(1)],[B(2) A(2)],'Linewidth',3) %line of thigh
hold on
scatter(S(1),S(2),'o','filled','b');

%% chart configuration
title('Coordinate system in center of foot');
axis([-2*L3 3*L3 -10 L2+L1+10]);

end

