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
% figure, imhist(grayBackground,256);
% figure, imhist(grayNewImg,256);

%% Convert to binary images
binaryBackground = imbinarize(grayBackground,0.8);
binaryNewImg = imbinarize(grayNewImg,0.8);
% figure, imshow(binaryBackground);
% figure, imshow(binaryNewImg);

%% Isolate foreground
foreground = bitxor(binaryNewImg, binaryBackground);
% figure, imshow(foreground);
se = strel('disk', 2);
isolatedForeground = imerode(foreground, se);
% figure, imshow(isolatedForeground);

%% Identify connected components
connectedComponents = bwconncomp(isolatedForeground);

%% Use regionprops to compute area/ find centroids
regProps = regionprops(connectedComponents);

%% Use regionprops to find centroid
regCentroids = regionprops(connectedComponents, 'centroid');
centroids = cat(1, regCentroids.Centroid);

%% Plot x on objects
% hold on
% for x = 1:numel(S)
%     plot(centroids(x,1),centroids(x,2),'rx');
% end
% hold off

%% Label image regions
% L = bwlabel(binaryImg);
% figure,imshow(binimg)
% hold on
% for i = 1:numel(cent)
%     c = cent(i).Centroid;
%     text(c(1), c(2), sprintf('%d', i), ...
%         'HorizontalAlignment', 'center', ...
%         'VerticalAlignment', 'middle');
% end
% hold off

% create colors matrix
% empty = 0, red = 1, green = 2, blue = 3
% centroids: [[210,398],[211,126],[345,247],[572,293]]
% centroids colors: [green,purple,red,blue]
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
