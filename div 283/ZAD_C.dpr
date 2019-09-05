program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [1..110] of integer;
   b:array [1..110] of string;
   n,m,i,j,k:integer;
function srv(x:integer):boolean;
var
   i:integer;
   f:boolean;
begin
   f:=false;
   for i:=1 to k do
      begin
         if (b[x][a[i]]>b[x-1][a[i]]) then break
         else if  (b[x][a[i]]<b[x-1][a[i]]) then
            begin
               f:=true;
               break;
            end;
      end;
   srv:=f;
end;
begin
   readln(n,m);
   for i:=1 to n do readln(b[i]);
   k:=0;
   for i:=1 to m do
      begin
         inc(k);
         a[k]:=i;
         for j:=2 to n do
            if srv(j) then
               begin
                  dec(k);
                  break;
               end;
      end;
   writeln(m-k);
   readln;
end.
