% ECE 4950 Spring 2020
% Group Fore
% Encoder Graph
tgOut = tg;
runTime = tgOut.TimeLog;
runOutput = tgOut.OutputLog;
fig = figure();
plot([0,14.5],[0,0],'LineStyle','-','Color',[0,0,0],'LineWidth',1);
hold on;
plot([0,0],[-250,250],'LineStyle','-','Color',[0,0,0],'LineWidth',1);
p1 = plot(runTime,runOutput,'LineStyle','-','Color',[1,0,0],'LineWidth',2);
hold off;
axis([0,14.5,-250,250]);
title('Encoder Output');
xlabel('time (s)');
ylabel('output');
savefig(fig, 'encoder_graph');
save('encoder_data');
