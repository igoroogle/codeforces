program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const
     a:array[1..8] of string =  ('vaporeon','jolteon','flareon','espeon','umbreon','leafeon','glaceon','sylveon');
var
   i,j,n:integer;
   s:string;
   pr:boolean;
begin
   readln(n);
   readln(s);
   for i:=1 to 8 do
      begin
         if (length(a[i])=n) then
            begin
               pr:=true;
               for j:=1 to n do
               begin
                  if (s[j]<>'.') and (a[i][j]<>s[j]) then
                     begin
                        pr:=false;
                        break;
                     end;
               end;
               if (pr) then
                  begin
                     writeln(a[i]);
                     readln;
                     halt;
                  end;
            end;
      end;
end.
