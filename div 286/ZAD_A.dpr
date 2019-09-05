program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   s,s1:string;
   ch:char;
   i:integer;
function palin(s:string):boolean;
var
   i:integer;
   f:boolean;
begin
   f:=true;
   for i:=1 to length(s) div 2 do
      if (s[i]<>s[length(s)-i+1]) then
         begin
            f:=false;
            break;
         end;
   palin:=f;
end;
begin
   readln(s);
   for ch:='a' to 'z' do
      begin
         s1:=ch+s;
         if (palin(s1)) then
            begin
               writeln(s1);
               readln;
               halt;
            end;
      end;
   for i:=1 to length(s)-1 do
      for ch:='a' to 'z' do
         begin
            s1:=copy(s,1,i)+ch+copy(s,i+1,length(s)-i+1);
         if (palin(s1)) then
            begin
               writeln(s1);
               readln;
               halt;
            end;
         end;
    for ch:='a' to 'z' do
      begin
         s1:=s+ch;
         if (palin(s1)) then
            begin
               writeln(s1);
               readln;
               halt;
            end;
      end;
   writeln('NA');
   readln;
end.
