% Testing of the output

fileID = fopen('circle_pts.txt','r');
formatspec = '%f'
array = fscanf(fileID,formatspec);
sX = 0.0;
sY = 0.0;

% getting X- coordinates
Mat_1 = zeros(50, 1);
c=1;
for i = 1:2:100;
    Mat_1(c,:) = array(i);
    sX = sX + array(i);
    c=c+1;
end
display(Mat_1)

% getting Y- coordinates
Mat_2 = zeros(50, 1);
c = 1;
for j = 2:2:100;
    Mat_2(c,:) = array(j);
    sY = sY + array(j);
    c=c+1;
end
display(Mat_2)
R =[Mat_1, Mat_2]
display(R)
plot(Mat_1, Mat_2, 'r*')
hold on

% th = 0:pi/50:2*pi;
r = 3.14726
x_o = 2.04082;
y_o = -3.02851;
% xunit = r * cos(th) + x;
% yunit = r * sin(th) + y;
% h = plot(xunit, yunit);
d = r*2;
px = x_o-r;
py = y_o-r;
h = rectangle('Position',[px py d d],'Curvature',[1,1]);
daspect([1,1,1])
title('Circle Fitting')


