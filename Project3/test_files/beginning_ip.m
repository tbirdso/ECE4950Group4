%% ECE 4950 Group Fore Image Processing

%% Init
clc; clear; close all;

% Define enums
BLUE = 1;
RED = 2;
GREEN = 3;
YELLOW = 4;
IDK_MAN = 0;

%% Load the images
imgStruct = load("img_with_lamp.mat");
background = imgStruct.background_img;
newImg = imgStruct.img4;
% figure, imshow(background);
% figure, imshow(newImg);

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
% figure, imshow(isolatedForeground);

%% Use regionprops to find centroids
connectedComponents = bwconncomp(isolatedForeground);
regProps = regionprops(connectedComponents);
regCentroids = regionprops(connectedComponents, 'centroid');
centroids = cat(1, regCentroids.Centroid);

%% Get coordinates and colors of centroids
numCentroids = numel(regCentroids);
hsvImg = rgb2hsv(newImg);
coords = zeros(numCentroids,2);
colors = zeros(numCentroids,1);
for i = 1:numCentroids
    coords(i,1) = round(centroids(i,1));
    coords(i,2) = round(centroids(i,2));
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
