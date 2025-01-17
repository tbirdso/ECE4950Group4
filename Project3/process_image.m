function [ image_data ] = process_image( background, newImg )
%% ECE 4950 Group Fore Image Processing

%% Init

% Define enums
BLUE = 1;
RED = 2;
GREEN = 3;
YELLOW = 4;
IDK_MAN = 0;

%% Convert to gray images
grayBackground = rgb2gray(background);
grayNewImg = rgb2gray(newImg);
% figure, imshow(grayBackground);
% figure, imshow(grayNewImg);
% figure, imhist(grayBackground,256);
% figure, imhist(grayNewImg,256);

%% Convert to binary images
binaryBackground = imbinarize(grayBackground,0.99);
binaryNewImg = imbinarize(grayNewImg,0.99);
% figure, imshow(binaryBackground);
% figure, imshow(binaryNewImg);

%% Isolate foreground
foreground = bitxor(binaryNewImg, binaryBackground);
% figure, imshow(foreground);
se = strel('disk', 2);
isolatedForeground = imerode(foreground, se);
figure, imshow(isolatedForeground);

%% Use regionprops to find centroids
connectedComponents = bwconncomp(isolatedForeground);
regProps = regionprops(connectedComponents);
regCentroids = regionprops(connectedComponents, 'centroid');
centroids = cat(1, regCentroids.Centroid);
regAreas = regionprops(connectedComponents, 'Area');

%% Filter out bad connected components
MIN_AREA = 600;
MAX_AREA = 1600;

filteredCents1 = zeros(100,2);
numObj = size(regAreas,1);
if (numObj > 100)
    numObj = 100;
end
count = 0;
for i = 1:numObj
    if ((regAreas(i).Area > MIN_AREA) && (regAreas(i).Area < MAX_AREA))
        count = count + 1;
        filteredCents1(count, 1) = centroids(i, 1);
        filteredCents1(count, 2) = centroids(i, 2);
    end
end

numCents = nnz(filteredCents1) / 2;
filteredCents = zeros(numCents, 2);
for i = 1:numCents
    filteredCents(i,1) = filteredCents1(i,1);
    filteredCents(i,2) = filteredCents1(i,2);
end
%% Get coordinates and colors of centroids
numCentroids = size(filteredCents , 1);
hsvImg = rgb2hsv(newImg);
coords = zeros(numCentroids,2);
colors = zeros(numCentroids,1);
for i = 1:numCentroids
    coords(i,1) = round(filteredCents(i,1));
    coords(i,2) = round(filteredCents(i,2));
    curColor = hsvImg(coords(i,2),coords(i,1),1);
    if ((0 <= curColor)&&(curColor < 0.14)) || (curColor > 0.88)
        colors(i) = RED;
    elseif (0.14 <= curColor)&&(curColor < 0.22)
        colors(i) = YELLOW;
    elseif (0.22 <= curColor)&&(curColor < 0.44)
        colors(i) = GREEN;
    elseif (0.44 <= curColor)&&(curColor < 0.75)
        colors(i) = BLUE;
    else
        colors(i) = IDK_MAN; 
    end
end

%% Create image_data matrix
% image_data = [color, xPos, yPos]
image_data = zeros(numCentroids, 3);
for i = 1:numCentroids
    image_data(i,1) = colors(i);    % colors
    image_data(i,2) = coords(i,1);  % x positions
    image_data(i,3) = coords(i,2);  % y positions
end

%% Plot the extra info in an overlay
hold on
for i = 1:numCentroids
    str = {num2str(image_data(i,2)), num2str(image_data(i,3))};
    text(image_data(i,2), image_data(i,3), num2str(image_data(i,1)), 'Color','red');
    text((image_data(i,2) + 5), (image_data(i,3) + 5), str,'Color','red');
end
hold off
end

