function varargout = GUI_Senior_Design(varargin)
% GUI_SENIOR_DESIGN MATLAB code for GUI_Senior_Design.fig
%      GUI_SENIOR_DESIGN, by itself, creates a new GUI_SENIOR_DESIGN or raises the existing
%      singleton*.
%
%      H = GUI_SENIOR_DESIGN returns the handle to a new GUI_SENIOR_DESIGN or the handle to
%      the existing singleton*.
%
%      GUI_SENIOR_DESIGN('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI_SENIOR_DESIGN.M with the given input arguments.
%
%      GUI_SENIOR_DESIGN('Property','Value',...) creates a new GUI_SENIOR_DESIGN or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before GUI_Senior_Design_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to GUI_Senior_Design_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help GUI_Senior_Design

% Last Modified by GUIDE v2.5 12-Mar-2020 13:27:50

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @GUI_Senior_Design_OpeningFcn, ...
                   'gui_OutputFcn',  @GUI_Senior_Design_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before GUI_Senior_Design is made visible.
function GUI_Senior_Design_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to GUI_Senior_Design (see VARARGIN)

% Choose default command line output for GUI_Senior_Design
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes GUI_Senior_Design wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = GUI_Senior_Design_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in push_run.
function push_run_Callback(hObject, eventdata, handles)
% hObject    handle to push_run (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

cur_index = get_param('modified_motor/Run', 'Value');
if cur_index == '0'
    set_param('modified_motor/Run', 'Value', '1');
    
else
    set_param('modified_motor/Run', 'Value', '0');
end

% --- Executes on selection change in menu_color.
function menu_color_Callback(hObject, eventdata, handles)
% hObject    handle to menu_color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
color_choice = 0;
color_contents = cellstr(get(hObject,'String'));
color = num2str(color_contents{get(hObject,'Value')});
switch color
    case 'Blue'
        color_choice = 1;
    case 'Red'
        color_choice = 2;
    case 'Green'
        color_choice = 3;
    case 'Yellow'
        color_choice = 4;
    otherwise
        color_choice = 0;
end
set_param('modified_motor/UI/Color', 'Value', int2str(color_choice));
% Hints: contents = cellstr(get(hObject,'String')) returns menu_color contents as cell array
%        contents{get(hObject,'Value')} returns selected item from menu_color


% --- Executes during object creation, after setting all properties.
function menu_color_CreateFcn(hObject, eventdata, handles)
% hObject    handle to menu_color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% Hints: contents = cellstr(get(hObject,'String')) returns menu_shape contents as cell array
%        contents{get(hObject,'Value')} returns selected item from menu_shape



% --- Executes on selection change in menu_mode.
function menu_mode_Callback(hObject, eventdata, handles)
% hObject    handle to menu_mode (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
mode_choice = 0;
mode_contents = cellstr(get(hObject,'String'));
mode = num2str(mode_contents{get(hObject,'Value')});
switch mode
    case 'All Stickers'
        mode_choice = 1;
    case 'Stickers By Color'
        mode_choice = 2;
    case 'Specific Sticker'
        mode_choice = 3;
    otherwise
        mode_choice = 0;
end
set_param('modified_motor/UI/Mode', 'Value', int2str(mode_choice));

% Hints: contents = cellstr(get(hObject,'String')) returns menu_mode contents as cell array
%        contents{get(hObject,'Value')} returns selected item from menu_mode


% --- Executes during object creation, after setting all properties.
function menu_mode_CreateFcn(hObject, eventdata, handles)
% hObject    handle to menu_mode (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function sticker_location_Callback(hObject, eventdata, handles)
% hObject    handle to sticker_location (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
sticker_location_degrees = str2double(get(hObject,'String'))
stick_location_deg_capped = mod(sticker_location_degrees, 360);
if stick_location_deg_capped > 180
    stick_location_deg_capped = stick_location_deg_capped - 360;
end
sticker_location_radians = stick_location_deg_capped * pi/180;

set_param('modified_motor/UI/Position', 'Value', num2str(sticker_location_radians));

% Hints: get(hObject,'String') returns contents of sticker_location as text
%        str2double(get(hObject,'String')) returns contents of sticker_location as a double


% --- Executes during object creation, after setting all properties.
function sticker_location_CreateFcn(hObject, eventdata, handles)
% hObject    handle to sticker_location (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in push_take_picture.
function push_take_picture_Callback(hObject, eventdata, handles)
% hObject    handle to push_take_picture (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
WEBCAM_NAME = 'HP USB Webcam';
camera = webcam(WEBCAM_NAME);

img = snapshot(camera);

clear camera;

imwrite(img, 'img1.png');


% --- Executes on button press in push_backgroundpicture.
function push_backgroundpicture_Callback(hObject, eventdata, handles)
% hObject    handle to push_backgroundpicture (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
WEBCAM_NAME = 'HP USB Webcam';
camera = webcam(WEBCAM_NAME);

img_background = snapshot(camera);

clear camera;

imwrite(img_background, 'img1.png');

