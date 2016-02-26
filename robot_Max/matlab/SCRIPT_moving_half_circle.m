%Program calculate inverse kinematic of biped legs (2 DOF) and draw scheme
%Mateusz Perciñski
%Miko³aj Marcinkiewicz
%21-12-2015

clear all;
L1=130; % length of thigh
L2=100; %length of shin
L3=70; %length of foot

cp=0;
r=10;
height=200;

for i=1:(4*r)


if i<2*r
    x_a=r+cp-i; %20
    y_a=height;
    
    x_b=-r+cp+i; %-20
    y_b=height-sqrt(r^2-(x_b-cp)^2); 
else
    x_a=-3*r+cp+i; %-60
    y_a=height-sqrt(r^2-(x_a-cp)^2); 
    
    x_b=3*r+cp-i; %60
    y_b=height;
end


%% INVERSE KINEMATIC %%%
S_R=[x_a y_a]';
S_L=[x_b y_b]';
[PHI_R, PHI_L]=inverseKinematic4DOF_1(S_R, S_L, L1, L2, L3);

%% Draw
drawLegs4DOF_1(PHI_R, PHI_L ,L1, L2, L3);

%%

 F(i)=getframe; % pobieranie kolejnych klatek
clf;
end

 movie(F,2,80) %
