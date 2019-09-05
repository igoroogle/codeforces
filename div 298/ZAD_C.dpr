program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n,a,s,l,r,osts:int64;
   i:integer;
   d:array [1..200010] of integer;
begin
   read(n,a);
   s:=0;
   for i:=1 to n do
      begin
         read(d[i]);
         s:=s+d[i];
      end;
   for i:=1 to n do
      begin
         osts:=s-d[i];
         if (osts<a) then l:=a-osts
         else l:=1;
         r:=a-n+1;
         if (r>d[i]) then r:=d[i];
         write(l-1+d[i]-r,' ');
      end;
   readln;
   readln;
end.
