%Program compares line plots in two coordinates systems:
%   one with center in hip, second one with center in ceter of foot
%   author: Mateusz Percinski
%   date:   2016-02-02

close all;
clear all;
L1=130; % length of thigh
L2=100; %length of shin
L3=70; %length of foot

S=[0 170]';
S2=[0 170]';

[PHI, PHI2]=inverseKinematic4DOF_1(S,S2,L1, L2, L3);


subplot(1,2,1);
drawLegs4DOF_1(PHI,PHI2, L1, L2, L3);
subplot(1,2,2);
drawLeg2DOF_2(PHI, L1, L2, L3);
