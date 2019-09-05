program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n,i:integer;
   a,b,c:array [1..110] of integer;
procedure rec(f,l:integer);
var
   k,i,a1,b1:integer;
begin
   if (f>=l) then exit;
   k:=(f+l) div 2;
   writeln('Q ',f,' ',k);
   flush(output);
   for i:=f to k do read(b[i]);
   a1:=f;
   b1:=k;
   for i:=f to l do
      begin
         if (a1>k) or (b[a1]>a[i]) then
            begin
               inc(b1);
               c[b1]:=a[i];
            end
         else inc(a1);
      end;
   for i:=f to k do a[i]:=b[i];
   for i:=k+1 to l do a[i]:=c[i];
   rec(f,k);
   rec(k+1,l);
end;
begin
   readln(n);
   for i:=1 to n do a[i]:=i;
   rec(1,n);
   write('A ');
   for i:=1 to n-1 do write(a[i],' ');
   writeln(a[n]);
   flush(output);
end.
