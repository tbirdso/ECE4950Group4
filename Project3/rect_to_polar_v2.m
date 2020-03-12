
% PURPOSE - Convert rectangular object coordinates to angle for
%           motor position
% INPUTS
%   - X, Y coordinates == center coords of each object
% OUTPUTS
%   - Vector of angles (radians) ordered ascending
% NOTES
%   - Theta == 0 is at the east of the map
%   - Positive angles are in south plane
%   - Negative angles are in north plane
%   - Camera origin (0,0) is at NW corner
%   - Game board origin is at image center
function Angles_sorted = rect_to_polar_v2( center_coords )

X_COL = 1;
Y_COL = 2;

% TODO: confirm actual frame dimensions
IMG_LENGTH_X = 640;
IMG_HEIGHT_Y = 480;


% Get the game board center (Approx. Motor Location) 
% so we can calculate relative angles
MotX = IMG_LENGTH_X/2;

MotY = IMG_HEIGHT_Y/2;

numObjects = size(center_coords, 1);
Angles = zeros(numObjects, 1);

for i = 1:numObjects
    Xdiff = center_coords(i,X_COL) - MotX;
    Ydiff = center_coords(i,Y_COL) - MotY;
    Angles(i) = atan(Ydiff/Xdiff);
   
    % Quandrant dependent angle math
    % Q4
    if ((Xdiff > 0) && (Ydiff < 0))
        Angles(i) = Angles(i);
    % Q3
    elseif((Xdiff < 0) && (Ydiff < 0))
        Angles(i) = Angles(i) - pi;
    % Q2
    elseif((Xdiff < 0) && (Ydiff > 0))
        Angles(i) = Angles(i) + pi;
    elseif((Xdiff > 0) && (Ydiff > 0))
        % may need to fix this, this is 4th quadrant
        Angles(i) = Angles(i);
    % Special case: angle is at -pi
    elseif((Ydiff == 0) && (Xdiff < 0))
        Angles(i) = -pi;
    elseif((Xdiff == 0) && (Ydiff == 0))
        Angles(i) = 0;
    end
end

Angles_sorted = sort(Angles);


end