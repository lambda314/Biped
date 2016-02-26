function drawLegs4DOF_1(PHI_R, PHI_L, L1, L2, L3)
%drawLegs4DOF_1 draws scheme with legs configuration
%
%   author: Mateusz Percinski
%   date:   2016-02-02
%
%   Coordinate system in hip
%
%   INPUTS: PHI_R - matrix 3x1 - angles in joints of right foot
%           PHI_L - matrix 3x1 - angles in joints of left foot
%           L1    - matrix 1x1 - length of thigh
%           L2    - matrix 1x1 - length of shin
%           L3    - matrix 1x1 - length of foot
%

%% POINTS DEFINITIONS FOR SCHEME
%% left leg
P0_a=[0 0];
P1_a=[L1*sin(PHI_R(1)) -L1*cos(PHI_R(1))];
P2_a=[L1*sin(PHI_R(1))-L2*sin(PHI_R(2)-PHI_R(1)) -L1*cos(PHI_R(1))-L2*cos(PHI_R(2)-PHI_R(1))];
P3_a=[L1*sin(PHI_R(1))-L2*sin(PHI_R(2)-PHI_R(1))-L3*cos(PHI_R(3)+pi-PHI_R(1)) -L1*cos(PHI_R(1))-L2*cos(PHI_R(2)-PHI_R(1))+L3*sin(PHI_R(3)+pi-PHI_R(1))];

%% right leg
P0_b=[0 0];
P1_b=[L1*sin(PHI_L(1)) -L1*cos(PHI_L(1))];
P2_b=[L1*sin(PHI_L(1))-L2*sin(PHI_L(2)-PHI_L(1)) -L1*cos(PHI_L(1))-L2*cos(PHI_L(2)-PHI_L(1))];
P3_b=[L1*sin(PHI_L(1))-L2*sin(PHI_L(2)-PHI_L(1))-L3*cos(PHI_L(3)+pi-PHI_L(1)) -L1*cos(PHI_L(1))-L2*cos(PHI_L(2)-PHI_L(1))+L3*sin(PHI_L(3)+pi-PHI_L(1))];

%% DRAWING SCHEME %
%% left leg (blue)
line([P0_b(1) P1_b(1)],[P0_b(2) P1_b(2)],'Linewidth',3) %line of thigh
line([P1_b(1) P2_b(1)],[P1_b(2) P2_b(2)],'Linewidth',3) %line of shin
line([P2_b(1) P3_b(1)],[P2_b(2) P3_b(2)],'Linewidth',3) %line of foot
hold on
scatter(P2_b(1)+L3/2,P3_b(2),'o','filled','b');
hold on

%% right leg (red)
line([P0_a(1) P1_a(1)],[P0_a(2) P1_a(2)],'Color','r','Linewidth',3) %line of thigh
line([P1_a(1) P2_a(1)],[P1_a(2) P2_a(2)],'Color','r','Linewidth',3) %line of shin
line([P2_a(1) P3_a(1)],[P2_a(2) P3_a(2)],'Color','r','Linewidth',3) %line of foot
hold on
scatter(P2_a(1)+L3/2,P3_a(2),'o','filled','r');

%% chart configuration
title('Coordinate system in hip');
axis([-2*L3 3*L3 -L1-L2-10 0]);

end

