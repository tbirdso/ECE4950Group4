% ECE 4950 Spring 2020
% Group Fore
% 100 Hz Sine Graph
clc; close all;
tgOut = tg;
runTime = tgOut.TimeLog;
runOutput = tgOut.OutputLog;
tStop = find(runTime == 0.02);
figTime = runTime(1:tStop);
figOutput = runOutput(1:tStop,1);
figInput = runOutput(1:tStop,2);
fig = figure();
plot([0,runTime(tStop)],[0,0],'LineStyle','-','Color',[0,0,0],'LineWidth',1);
hold on;
plot([0,0],[-1,1],'LineStyle','-','Color',[0,0,0],'LineWidth',1);
p1 = plot(figTime,figOutput,'LineStyle','-','Color',[1,0,0],'LineWidth',2);
p2 = plot(figTime,figInput,'LineStyle','--','Color',[0,0,1],'LineWidth',2);
hold off;
axis([0,runTime(tStop),-1,1]);
title('100Hz Analog Output');
xlabel('time (s)');
ylabel('output (V)');
legend([p1,p2],'Output','Input',...
    'Location','northwest')
savefig(fig, '100hz_graph');
save('100hz_data');
