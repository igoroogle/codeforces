program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a,d:array [0..20010] of integer;
   i,j,k,m,n:integer;
procedure quicksort(f,l:integer);
var
   i,j:integer;
   x,dd:int64;
begin
   x:=a[random(l-f+1)+f];
   i:=f;
   j:=l;
   repeat
       while (a[i]<x) do inc(i);
       while (a[j]>x) do dec(j);
       if (i<=j) then
         begin
            dd:=a[i];
            a[i]:=a[j];
            a[j]:=dd;
            inc(i);
            dec(j);
         end;
   until i>j;
   if (i<l) then quicksort(i,l);
   if (f<j) then quicksort(f,j);
end;
begin
   readln(n,k);
   for i:=1 to n do read(a[i]);
   readln;
   quicksort(1,n);
   if (n<k) then k:=n;
   d[0]:=0;
   for i:=1 to n do
      begin
         d[i]:=d[i-1]+(a[i]-1)*2;
      end;
  for i:=1 to n do
     begin
        m:=i-k;
        if (0>m) then m:=0;
        for j:=m to i-1 do
           begin
              if (d[j]+abs(1-a[i])*2<d[i]) then
                begin
                   d[i]:=d[j]+abs(1-a[i])*2;
                end;
           end;
     end;
  writeln(d[n]);
end.
