%A brief tutorial to using Image Processing Functions in MATLAB.
%This code loads an image and processes it using regionprops and connected
%components.
%Many lines of code have been commented out, you can uncomment them to see
%the output. 
%When in doubt, MATLAB Help files will come in handy. 
%Written for ECE 4950 Senior Design at Clemson University
%Author: Venkataraman Ganesh  
%10 October 2014

clc; clear; close all;

%load the image: 
img = imread('test_img.jpg');
figure, imshow(img);
grayimg = rgb2gray(img);

%Convert to a binary image from the intensity image
compbinimg = imbinarize(grayimg,0.5);
binimg = imcomplement(compbinimg);
% figure, imshow(binimg);

%Use CC to identify connected components
CC = bwconncomp(binimg);

%Use regionprops to compute area/ find centroids
S = regionprops(CC,'Area');

%g= S(1).Area; %Values stored in a struct

%Use regionprops to find centroid
cent = regionprops(binimg, 'centroid');
centroids = cat(1, cent.Centroid); %struct holds the centroids

% figure, imshow(grayimg)
% hold on
% for x = 1:numel(S)
%     plot(centroids(x,1),centroids(x,2),'rx');
% end
% hold off

%label image regions
L = bwlabel(binimg);
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
n = 17; % number of wells
gameState.wellCoord = [[210,398] [211,126] [345,247] [572,293] [] [] []];
gameState.wellLoc = [30,60,90,135,180,-45,-90,-120,-150];
gameState.wellColor = zeros(1,n);
for x = 1:4
%    centroids(x,1),centroids(x,2)
    if (isequal(img(round(centroids(x,1)),round(centroids(x,2))),[255,255,255]))
        gameState.wellColor(x) = 1;
    end
end
