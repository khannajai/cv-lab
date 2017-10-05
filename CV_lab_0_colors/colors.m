
%peppers.png red.png blue.png
RGB = imread('peppers.png');
size(RGB)
imshow(RGB);
%title(image)

R = RGB(:,:,1);
size(R)
max(max(R))
min(min(R))
%subplot(2,2,2);
imshow(R);
%title(Red)


G=RGB(:,:,2)
size(G)
max(max(G))
min(min(G))
%subplot(2,2,3);
imshow(G);
%title(Green)

B=RGB(:,:,3)
size(B)
max(max(B))
min(min(B))
%subplot(2,2,4);
imshow(B);
%title(Blue)

NumBins=20

h_R_hist=histogram(R(:),NumBins,'FaceColor','r')
imshow(h_R_hist);
%title(redhistogram)
h_G_hist=histogram(G(:),NumBins,'FaceColor','g')
imshow(h_G_hist);
%title(greenhistogram)
h_B_hist=histogram(B(:),NumBins,'FaceColor','b')
imshow(h_B_hist);
%title(bluehistogram)



HSV=rgb2hsv(RGB);
H = HSV(:,:,1)
S = HSV(:,:,2)
V = HSV(:,:,3)
imshow(H);
%title(Hue)
imshow(S);
%title(Saturation)
imshow(V);
%title(Value)


h_H_hist=histogram(H(:),NumBins,'FaceColor','h')
imshow(h_H_hist);
title(huehistogram)
h_S_hist=histogram(S(:),NumBins,'FaceColor','s')
imshow(h_S_hist);
title(saturationhistogram)
h_V_hist=histogram(V(:),NumBins,'FaceColor','v')
imshow(h_V_hist);
title(valuehistogram)



