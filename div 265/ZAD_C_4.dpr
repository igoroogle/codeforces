program antepol;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  l,i,z,p:integer;
  s:string;
function incl():integer;
  var
    i:integer;
  begin
    incl := 0;
    s[length(s)] := chr(ord(s[length(s)])+1);
    i :=  length(s);

    while (ord(s[i]) > p) do
      begin
        if i = 1 then incl := 1;
        if i = 1 then break;
        s[i] := 'a';
        dec(i);
        s[i] := chr(ord(s[i])+1);
      end;

  end;
function prover ():integer;
  var
    i,proverk:integer;

  begin
  proverk := 1;
    for i := length(s)-1 downto 1 do
      begin
        if s[i] = s[i+1] then
          begin
            proverk := 0;
            break;
          end;
      end;
      if proverk = 1 then
    for i := length(s)-2 downto 1 do
      begin
        if s[i] = s[i+2] then
          begin
            proverk := 0;
            break;
          end;
      end;


    prover := proverk;
  end;
begin
  l := 0;
  readln(z,p);
  p := ord('a') + p - 1;
  readln(s);
  while incl() = 0 do
    begin
      if prover() = 1 then
      begin
       writeln(s);
        l := 1;
        break;
      end;
    end;
  if l = 0 then writeln('NO');

  readln;
  readln;


end.
 