function [ Points ] = pointsOnLine(Start, Stop, n)
%pointsOnLine creates array of n points on straight line between two points
%
%   author: Mateusz Percinski
%   date:   2016-02-02
%
%   INPUTS: Start - matrix 2x1 - coordinates of start point
%           Stop  - matrix 2x1 - coordinates of end point
%           n - point count
%
%   OUTPUTS: Points - matrix 2xn - coordinates of n points

dx=(Stop(1)-Start(1))/(n-1) 
dy=(Stop(2)-Start(2))/(n-1) 


for i=1:n
    Points(1,i)=Start(1)+dx*(i-1)
    Points(2,i)=Start(2)+dy*(i-1)
end

end

