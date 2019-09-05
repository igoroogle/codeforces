program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   a,b,c:array [1..2010,1..2010] of int64;
   n,i,j,p,x1,y1,x2,y2,ind:integer;
   max1,max2,pr:int64;
begin
   readln(n);
   for i:=1 to n do
      for j:=1 to n do read(a[i,j]);
   readln;
   for p:=1 to n do
       begin
          i:=p;
          j:=1;
          b[p,1]:=0;
          while (i<=n) and (j<=n) do
             begin
                b[p,1]:=b[p,1]+a[i,j];
                inc(i);
                inc(j);
             end;
       end;
   for p:=1 to n do
      begin
         i:=1;
         j:=p;
         b[1,p]:=0;
          while (i<=n) and (j<=n) do
             begin
                b[1,p]:=b[1,p]+a[i,j];
                inc(i);
                inc(j);
             end;
      end;
   for p:=1 to n do
      begin
         i:=p;
         j:=1;
         c[p,1]:=0;
         while (i<=n) and (j>=1) do
            begin
               c[p,1]:=c[p,1]+a[i,j];
               inc(i);
               dec(j);
            end;
      end;
   for p:=1 to n do
      begin
         i:=1;
         j:=p;
         c[1,p]:=0;
         while (i<=n) and (j>=1) do
            begin
               c[1,p]:=c[1,p]+a[i,j];
               inc(i);
               dec(j);
            end;
      end;
   x1:=0;
   y1:=0;
   max1:=-1;
   for i:=1 to n do
      begin
         if (odd(i)) then j:=1
         else j:=2;
         while (j<=n) do
            begin
               if (i<j) then ind:=i
               else ind:=j;
               pr:=b[i-ind+1,j-ind+1];
               if (abs(i-1)<abs(j-n)) then ind:=abs(i-1)
               else ind:=abs(j-n);
               pr:=pr+c[i-ind,j+ind];
               pr:=pr-a[i,j];
               if (pr>max1) then
                  begin
                     max1:=pr;
                     x1:=i;
                     y1:=j;
                  end;
               inc(j,2);
            end;
      end;
    max2:=-1;
    x2:=0;
    y2:=0;
    for i:=1 to n do
      begin
         if (odd(i)) then j:=2
         else j:=1;
         while (j<=n) do
            begin
               if (i<j) then ind:=i
               else ind:=j;
               pr:=b[i-ind+1,j-ind+1];
               if (abs(i-1)<abs(j-n)) then ind:=abs(i-1)
               else ind:=abs(j-n);
               pr:=pr+c[i-ind,j+ind];
               pr:=pr-a[i,j];
               if (pr>max2) then
                  begin
                     max2:=pr;
                     x2:=i;
                     y2:=j;
                  end;
               inc(j,2);
            end;
      end;
      writeln(max1+max2);
      writeln(x1,' ',y1,' ',x2,' ',y2);
      writeln(b[1,1]+b[2,1]+c[2,n]+c[3,n]);
   readln;
end.
