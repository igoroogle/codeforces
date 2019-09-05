program ZAD_D;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a,b,c,x,y,ma,mb:array [0..200010] of integer;
   i,j,n,k,z,s,kp,a1,b1:integer;
procedure quicksort (f,l:integer);
var
   dd,x1,y1,i,j,t:integer;
begin
   randomize;
   i:=f;
   j:=l;
   t:=random(l-f+1)+f;
   x1:=x[t];
   y1:=y[t];
   repeat
      while (x[i]<x1) or ((x[i]=x1) and (y[i]<y1)) do inc(i);
      while (x[j]>x1) or ((x[j]=x1) and (y[j]>y1)) do dec(j);
      if (i<=j) then
         begin
            dd:=x[i];
            x[i]:=x[j];
            x[j]:=dd;
            dd:=y[i];
            y[i]:=y[j];
            y[j]:=dd;
            inc(i);
            dec(j);
         end;
   until i>j;
   if (i<l) then quicksort(i,l);
   if (f<j) then quicksort(f,j);
end;
begin
   read(n);
   for i:=0 to 200010 do
      begin
         c[i]:=0;
         ma[i]:=0;
         mb[i]:=0;
      end;
   a[0]:=0;
   b[0]:=0;
   for i:=1 to n do
      begin
         read(z);
         a[i]:=a[i-1];
         b[i]:=b[i-1];
         if (z=1) then
            begin
               inc(a[i]);
               ma[a[i]]:=i;
            end
         else
            begin
               inc(b[i]);
               mb[b[i]]:=i;
            end;
         if (a[i]<>b[i]) then
            begin
               if (a[i]>b[i]) then c[a[i]]:=i
               else c[b[i]]:=i;
            end;
      end;
   k:=0;
   for i:=1 to n do
      if (c[i]<>0) then
         begin
            j:=c[i];
            s:=1;
            a1:=0;
            b1:=0;
            if (a[j]>b[j]) then inc(a1)
            else inc(b1);
            while true do
               begin
                  if (j=n) then
                     begin
                        if (a1<>b1) then
                           begin
                              inc(k);
                              if (a1>b1) then x[k]:=a1
                              else x[k]:=b1;
                              y[k]:=i;
                           end;
                        break;
                     end;
                  kp:=-1;
                  if (ma[a[j]+i]>j) and (ma[a[j]+i]<=n) then kp:=ma[a[j]+i];
                  if (mb[b[j]+i]>j) and (mb[b[j]+i]<=n) and ((kp=-1) or (mb[b[j]+i]<kp)) then kp:=mb[b[j]+i];
                  if (kp=-1) then break;
                  if (a[kp]-a[j]=b[kp]-b[j]) then break;
                  if (a[kp]-a[j]>b[kp]-b[j]) then inc(a1)
                  else inc(b1);
                  j:=kp;
                  inc(s);
               end;
         end;
   if (k>0) then quicksort(1,k);
   writeln(k);
   for i:=1 to k do writeln(x[i],' ',y[i]);
   readln;
   readln;
end.
