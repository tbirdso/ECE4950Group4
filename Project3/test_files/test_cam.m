close all; clear('cam');

cam_list = webcamlist;
cam_name = cam_list{2};
cam = webcam(cam_name);

preview(cam);
closePreview(cam);

% img = snapshot(cam);
% img2 = snapshot(cam);
% 
% imshow(img);
% figure();
% imshow(img2);

% diff = (img-img2);
