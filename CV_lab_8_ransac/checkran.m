% Testing of the output

fileID = fopen('pts_to_ransac.txt','r');
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

r1 = 0.529016;
x1 = 0.891802;
y1 = 0.913228;
d = r1*2;
px = x1-r1;
py = y1-r1;
h1 = rectangle('Position',[px py d d],'Curvature',[1,1]);
daspect([1,1,1])
title('Circle Fitting')
hold on
r2 = 0.811513;
x2 = 0.446972;
y2 = 0.400795;
d = r2*2;
px = x2-r2;
py = y2-r2;
h2 = rectangle('Position',[px py d d],'Curvature',[1,1]);
daspect([1,1,1])
 
hold on
r3 = 0.822412;
x3 = 1.0026;
y3 = 1.01034;
d = r3*2;
px = x3-r3;
py = y3-r3;
h3 = rectangle('Position',[px py d d],'Curvature',[1,1]);
daspect([1,1,1])


