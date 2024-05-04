function dilatado = resize(X)

 [L, C, dim] = size(X);

 if dim == 3
     X = rgb2gray(X);
 end
 L_dilatado = L*2;
 C_dilatado = C*2;
 dilatado = zeros(L_dilatado, C_dilatado);

 for i = 1:L
     for j = 1:C
         dilatado((i*2)-1,(j*2)-1)= X(i,j);
         dilatado( i*2   ,(j*2)-1)= X(i,j);
         dilatado((i*2)-1,(j*2))  = X(i,j);
         dilatado( i*2   ,(j*2))  = X(i,j);
     end
 end

end

