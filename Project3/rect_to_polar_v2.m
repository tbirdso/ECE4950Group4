function Angles = rect_to_polar_v2( center_coords, numObjects )

% Update these to actual frame dimensions
IMG_LENGTH = 826;
IMG_HEIGHT = 593;


% Get the game board center (Approx. Motor Location) 
% so we can calculate relative angles
MotX = IMG_LENGTH/2;
MotY = IMG_HEIGHT/2;
Angles = zeros(numObjects, 1);


for i = 1:numObjects
    Xdiff = center_coords(i,1) - MotX;
    Ydiff = center_coords(i,2) - MotY;
    Angles(i) = atan(Ydiff/Xdiff);
    Angles(i) = Angles(i) * 180/3.1415926535;
    
    % Quandrant dependent angle math
    if ((Xdiff > 0) && (Ydiff < 0))
        Angles(i) = Angles(i) * -1;
    elseif((Xdiff < 0) && (Ydiff < 0))
        Angles(i) = 180 - Angles(i);
    elseif((Xdiff < 0) && (Ydiff > 0))
        Angles(i) = 180 + (-1 * Angles(i));
    else
        % may need to fix this, this is 4th quadrant
        Angles(i) = Angles(i);
    end
end


end