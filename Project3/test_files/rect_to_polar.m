% PURPOSE - Convert rectangular object coordinates to angle for
%           motor position
% INPUTS
%   - X, Y coordinates
% OUTPUTS
%   - Magnitude, angle (rad)
% NOTES
%   - Theta == 0 is at the bottom of the map
%   - Positive angles are in RH plane
%   - Negative angles are in LH plane
%   - Camera origin (0,0) is at NW corner
%   - Game board origin is at image center

function angles = rect_to_polar( rect_coords )

% FIXME const values
IMG_LENGTH = 400;
IMG_HEIGHT = 400;

% FIXME this math is probably wrong

% Get the game board center so we can calculate relative angles
IMG_CENTER = [IMG_LENGTH / 2, IMG_HEIGHT / 2];

% Get (x,y) relative to the game board center
x_from_center = IMG_CENTER(1) - rect_coords(:,1);
y_from_center = IMG_CENTER(2) - rect_coords(:,2);

% Find cartesian angles where an eastward object is at theta == 0
cartesian_angles = atan(y_from_center ./ x_from_center);
angles = cartesian_angles;
%angles = - (cartesian_angles - pi/2);

end

