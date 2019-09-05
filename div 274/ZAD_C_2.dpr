program ZAD_C_2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a,b:array [1..5010] of integer;
   n,i,min:integer;
procedure quicksort (f,l:integer);
var
   i,j,t,x,y,dd:integer;
begin
   randomize;
   t:=random(l-f+1)+f;
   x:=a[t];
   y:=b[t];
   i:=f;
   j:=l;
   repeat
      while ((a[i]=x) and (b[i]<y)) or (a[i]<x) do inc(i);
      while ((a[j]=x) and (b[j]>y)) or (a[j]>x) do dec(j);
      if (i<=j) then
         begin
            dd:=a[i];
            a[i]:=a[j];
            a[j]:=dd;
            dd:=b[i];
            b[i]:=b[j];
            b[j]:=dd;
            inc(i);
            dec(j);
         end;
   until i>j;
   if (i<l) then quicksort(i,l);
   if (f<j) then quicksort(f,j);
end;
begin
   readln(n);
   for i:=1 to n do read(a[i],b[i]);
   readln;
   quicksort(1,n);
   min:=b[1];
   for i:=2 to n do
      begin
         if (b[i]>=min) then min:=b[i]
         else min:=a[i];
      end;
   writeln(min);
   readln;
end.
