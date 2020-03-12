%% ECE 4950 Group Fore Image Processing

%% Init
clc; clear; close all;

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

%% Detect colors of centroids
% empty = 0, red = 1, green = 2, blue = 3
numCentroids = numel(regCentroids);

%% Create image_data matrix
% image_data = [shape, color, xPos, yPos]
image_data = zeros(numCentroids, 4);
for i = 1:numCentroids
    image_data(i,1) = 1;    % shapes
    image_data(i,2) = 3;    % colors
    image_data(i,3) = round(centroids(i,1));    % x positions
    image_data(i,4) = round(centroids(i,2));    % y positions
end
% image_data(1:4,:) = [1, 1, 320, 0;
%     1, 1, 320, 0;
%     1, 1, 0, 240;
%     1, 2, 320, 480];
% n = 17; % number of wells
% gameState.wellCoord = [[210,398] [211,126] [345,247] [572,293] [] [] []];
% gameState.wellLoc = [30,60,90,135,180,-45,-90,-120,-150];
% gameState.wellColor = zeros(1,n);
% for x = 1:4
% %    centroids(x,1),centroids(x,2)
%     if (isequal(img(round(centroids(x,1)),round(centroids(x,2))),[255,255,255]))
%         gameState.wellColor(x) = 1;
%     end
% end
