program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const
   dl = 1010;
var
   a:array [0..dl,0..dl] of boolean;
   n,m,k,i,j,x,y:integer;
begin
   read(n,m,k);
   for i:=0 to dl do
      for j:=0 to dl do a[i,j]:=false;
   for i:=1 to k do
      begin
         read(x,y);
         a[x,y]:=true;
         if ((a[x+1,y]) and (a[x,y+1]) and (a[x+1,y+1])) or ((a[x-1,y]) and (a[x-1,y+1]) and (a[x,y+1])) or ((a[x-1,y-1]) and (a[x+1,y-1]) and (a[x+1,y])) or ((a[x-1,y-1]) and (a[x,y-1]) and (a[x-1,y])) then
            begin
               writeln(i);
               readln;
               readln;
               halt;
            end;
      end;
   writeln(0);
   readln;
   readln;
end.
