program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const
   st = 'qwertyuiopasdfghjkl;zxcvbnm,./';
var
   s:string;
   i:integer;
   ch:char;
begin
   readln(ch);
   readln(s);
   for i:=1 to length(s) do
      begin
         if (upcase(ch)='L') then s[i]:=st[pos(s[i],st)+1]
         else s[i]:=st[pos(s[i],st)-1];
      end;
   writeln(s);
   readln;
end.
