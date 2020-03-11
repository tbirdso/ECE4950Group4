
% PURPOSE - Convert rectangular object coordinates to angle for
%           motor position
% INPUTS
%   - X, Y coordinates == center coords of each object
% OUTPUTS
%   - Vector of angles (radians) ordered ascending
% NOTES
%   - Theta == 0 is at the bottom of the map
%   - Positive angles are in RH plane
%   - Negative angles are in LH plane
%   - Camera origin (0,0) is at NW corner
%   - Game board origin is at image center
function Angles_sorted = rect_to_polar_v2( center_coords )

% Update these to actual frame dimensions
IMG_LENGTH = 826;
IMG_HEIGHT = 593;


% Get the game board center (Approx. Motor Location) 
% so we can calculate relative angles
MotX = IMG_LENGTH/2;
MotY = IMG_HEIGHT/2;

numObjects = size(center_coords, 1);
Angles = zeros(numObjects, 1);


for i = 1:numObjects
    Xdiff = center_coords(i,1) - MotX;
    Ydiff = center_coords(i,2) - MotY;
    Angles(i) = atan(Ydiff/Xdiff);
    
    % Quandrant dependent angle math
    if ((Xdiff > 0) && (Ydiff < 0))
        Angles(i) = Angles(i) * -1;
    elseif((Xdiff < 0) && (Ydiff < 0))
        Angles(i) = pi - Angles(i);
    elseif((Xdiff < 0) && (Ydiff > 0))
        Angles(i) = pi + (-1 * Angles(i));
    else
        % may need to fix this, this is 4th quadrant
        Angles(i) = Angles(i);
    end
end

Angles_sorted = sort(Angles);


end