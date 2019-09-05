program ZAD_A_2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   k:array [1..11] of int64;
   a,b:array [0..100100] of int64;
   ind:array [0..100100] of integer;
   t1,a1,b1:int64;
   i,j,n,m,min,kol:integer;
procedure quicksort(f,l:integer);
var
   i,j,t,y,dd1:integer;
   dd,x:int64;
begin
   i:=f;
   j:=l;
   t:=random(l-f+1)+f;
   x:=a[t];
   y:=ind[t];
   repeat
      while (a[i]<x) or ((a[i]=x) and (ind[i]<y)) do inc(i);
      while (a[j]>x) or ((a[j]=x) and (ind[j]>y)) do dec(j);
      if (i<=j) then
         begin
            dd:=a[i];
            a[i]:=a[j];
            a[j]:=dd;
            dd:=b[i];
            b[i]:=b[j];
            b[j]:=dd;
            dd1:=ind[i];
            ind[i]:=ind[j];
            ind[j]:=dd1;
            inc(i);
            dec(j);
         end;
   until i>j;
   if (i<l) then quicksort(i,l);
   if (f<j) then quicksort(f,j);
end;
begin
   reset(input,'bank.in');
   assign(output,'bank.out');
   read(n,m);
   kol:=0;
   for i:=1 to 11 do k[i]:=0;
   for i:=1 to n do
      begin
         read(t1,a1,b1);
         min:=1;
         for j:=1 to m do
            if (k[j]<k[min]) then min:=j;
         if (t1>k[min]) then k[min]:=t1;
         k[min]:=k[min]+a1;
         inc(kol);
         ind[kol]:=i;
         a[kol]:=k[min];
         b[kol]:=b1;
      end;
   quicksort(1,kol);
   a[0]:=0;
   b[0]:=0;
   for i:=1 to kol do
      begin
         if (a[i-1]>a[i]) then a[i]:=a[i-1];
         a[i]:=a[i]+b[i];
      end;
   for i:=1 to kol do b[ind[i]]:=a[i];
   for i:=1 to kol do writeln(b[i]);
   readln;
   readln;
end.
