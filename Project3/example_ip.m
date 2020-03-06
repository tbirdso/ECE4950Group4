%% Init
clear; clc; close all;

%% Init Camera
cam_list = webcamlist;
cam_name = cam_list{2};
cam = webcam(cam_name);

%% Take Image
% img = snapshot(cam);
% imshow(img);

% If you want a preview
% preview(cam);
% closePreview(cam);

% If you don't have the camera
imgName = 'test_img.jpg';
img = imread(imgName);
figure();
imshow(img);

%% Convert to Grayscale
imgGray = rgb2gray(img);
figure();
imshow(imgGray);

%% Convert to Binary Image
threshLevel = 0.5;
imgBinary = imbinarize(imgGray, threshLevel);
figure();
imshow(imgBinary);

%% Isolate Circle Elements
se = strel('disk', 1);                  % need to look into strel()
imgOpenned = imopen(imgBinary, se);
figure();
imshow(imgOpenned);

%% Potentially Useful regionprops Stuff
imgRegion = regionprops(imgOpenned);
% imgRegion = regionprops(imgOpenned, 'Area');
% imgRegion = regionprops(imgOpenned, 'centroid');
% [labeled, numObjects] = bwlabel(imgOpenned, 4);
% stats = regionprops(labeled, 'Area');
% [imgRegionRows, imgRegionCols] = size(imgRegion);
% potentialImgArea = max([imgRegion.Area]);
% % if (size(imgRegion) == 0)
% if (imgRegionRows == 0 || imgRegionCols == 0 || potImgArea < 100)
%     area = 0;
% else
%     area = min([imgRegion.Area]);
% end