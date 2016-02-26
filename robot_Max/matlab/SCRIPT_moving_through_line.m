%script animates moving hip through straight line 
%
%   author: Mateusz Percinski
%   date:   2016-02-02
%
%%
close all;
clear all;

%% Dimensions
L1=130; % length of thigh
L2=100; %length of shin
L3=70; %length of foot

%% Create line to move
A1=[-40 130]' %Start point
A2=[0 200]'; %End point
n=20; % points count
Points=pointsOnLine(A1, A2, n);



%% Draw and Animate
for i=1:n
    PHI = inverseKinematic2DOF_2(Points(:,i), L1,L2, L3);
    PHI_all(:,i)=radtodeg(PHI); % Angles Array for movement
    drawLeg2DOF_2(PHI,L1,L2,L3);
    F(i)=getframe; % pobieranie kolejnych klatek
    clf;
end
axis equal
movie(F,-10,80) %
 
PHI_all
dlmwrite('file1.txt',PHI_all)

