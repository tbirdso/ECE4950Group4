% GUI for Project 3

modes = {'scan'; 'seek_color'; 'seek_position'};
colors = {'none'; 'red'; 'blue'};

mode_choice = menu('What to do?','scan', 'Find all instances of a color', 'Find a specific sticker');
fprintf('%d: %s', mode_choice, modes{mode_choice,:});

if mode_choice == 2
    color_choice = menu('What color to seek?', 'red', 'blue') + 1;
elseif mode_choice == 3
    pos_choice = menu('What sticker to seek?', 'FIXME');
end

% set_param('motor_params/UIBlock', 'mode_choice', mode_choice);
% set_param('motor_params/UIBlock', 'color_choice', mode_choice);