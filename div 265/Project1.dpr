program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   s:string;
   n,p,i,k:integer;
begin
   readln(n,p);
   readln(s);
   k:=n;
   for i:=n downto 1 do
      begin
         while (ord(s[i])<p) do
            begin
               if ((i<2) or (s[i-1]<>chr(ord(s[i])+1))) and ((i<3) or (s[i-2]<>chr(ord(s[i])+1))) then break
               else s[i]:=chr(ord(s[i])+1)
            end;
         if (ord(s[i])<p) then
            begin
               k:=i;
               break;
            end;
      end;
  if (ord(s[k])=p) then
     begin
        writeln('NO');
        halt;
     end;
  s[k]:=chr(ord(s[k])+1);
  for i:=k+1 to n do
     begin
        s[i]:='a';
        while (ord(s[i])<=p) do
            begin
               if ((i<2) or (s[i-1]<>s[i])) and ((i<3) or (s[i-2]<>s[i])) then break
               else s[i]:=chr(ord(s[i])+1)
            end;
         if (ord(s[i])>p) then
            begin
               writeln('NO');
               halt;
            end;

     end;
  writeln(s);
  readln;
end.
