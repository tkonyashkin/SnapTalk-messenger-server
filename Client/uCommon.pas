unit uCommon;

interface

uses DB, ADODB, DBGrids, Windows, SysUtils, ShellAPI, Forms, Variants, Dialogs,
     DBClient;


procedure ClearMemory (Obj : TObject);
procedure DataSetLocateKey (DS : TDataSet; KeyName : Variant; KeyValue : Variant);
procedure DataSetReload (DS : TDataSet);

procedure dbgTitleClick (Column: TColumn);
function GetTempDir : WideString; stdcall;
function ExecuteFile(const FileName, Params, DefaultDir: string; ShowCmd: Integer): THandle;
function DateTimeSubToStr (Value : Double) : string;

implementation



function DateTimeSubToStr (Value : Double) : string;
var
    //
    X, Y : Double;
begin
    //
    Result := '';

    X := Int (Value);
    Y := Frac(Value);
    if X >= 0 then
    begin
        //
        if Result <> '' then Result := Result + ' ';
            Result := Result + FloatToStr(X) + 'д';
    end;
    X := Int (Y * 24);
    Y := Frac(Y * 24);

    if X >= 0 then
    begin
        //
        if Result <> '' then Result := Result + ' ';
            Result := Result + FloatToStr(X) + 'ч';
    end;

    X := Int (Y * 60);

    if X >= 0 then
    begin
        //
        if Result <> '' then Result := Result + ' ';
            Result := Result + FloatToStr(X) + 'м';
    end;

end;

procedure ClearMemory (Obj : TObject);
    begin
        //
        if (Obj <> nil) then Obj.Free;
    end;

procedure DataSetLocateKey (DS : TDataSet; KeyName : Variant; KeyValue : Variant);
begin
    //
    if (DS.Locate(KeyName, KeyValue, []) = false) then
        raise Exception.Create('Не удалось найти строку с сохраненным значением ключа');

end;

procedure DataSetReload (DS : TDataSet);
var
    //
    KeyName, KeyValue : Variant;
    I : Integer;
    F : TField;
begin
    //
    KeyName := '';
    KeyValue := NULL;
    for I := 0 to DS.FieldCount - 1 do
    begin
        //
        F := DS.Fields.FieldByNumber (I);
        if (F is TAutoIncField) then
        begin
            //
            KeyName := F.FieldName;
            KeyValue := F.Value;
        end;
    end;
    DS.Close;
    DS.Open;
    if (KeyName <> '') then
    begin
        if (DS.Locate(KeyName, KeyValue, []) = false) then
            raise Exception.Create('Не удалось найти строку с сохраненным значением ключа');
    end;
end;

procedure dbgTitleClick (Column: TColumn);
var
    //
    T : TClientDataSet;
    SortType : TIndexOptions;

    procedure ClearAllTags ();
    var
        I : Integer;
        C : TDBGridColumns;
    begin
        //
        C := (Column.Grid as TDBGrid).Columns;
        for I := 0 to C.Count - 1 do
        begin
            //
            if (C[I].Field.FieldName <> Column.Field.FieldName) then
            begin
                //
                C[I].Field.Tag := 0;
                C[I].Title.Caption := C[I].Field.DisplayName;
            end
            else
            begin
                //



            end;
        end;
    end;


begin
    //

    T := Column.Field.DataSet as TClientDataSet;
    Column.Field.Tag := Column.Field.Tag + 1;
    ClearAllTags ();

    if (Column.Field.Tag = 1) then
    begin
        SortType := [];
        Column.Title.Caption := Column.Field.DisplayName + ' (по возр.)';
    end;

    if (Column.Field.Tag = 2) then
    begin
        SortType := [ixDescending];
        Column.Title.Caption := Column.Field.DisplayName + ' (по убыв.)';
    end;

    if (Column.Field.FieldKind = fkData) then
    begin

        //
        T.IndexDefs.Clear;
        try
            T.DeleteIndex('IX');
        except
        end;
        T.AddIndex ('IX', Column.Field.FieldName, SortType + [ixCaseInsensitive]);
        T.IndexName := 'IX';
    end;

    if (Column.Field.FieldKind = fkLookup) then
    begin
         //
        T.IndexDefs.Clear;
        try
            T.DeleteIndex('IX');
        except
        end;
        T.AddIndex ('IX', Column.Field.KeyFields, SortType + [ixCaseInsensitive]);
        T.IndexName := 'IX';
    end;



    if (Column.Field.Tag >= 2) then Column.Field.Tag := 0;



end;

function GetTempDir : WideString; stdcall;
var
    Buffer : array[0..1023] of Char;
begin
    //
    GetTempPath (1024 - 1, &Buffer);
    SetString(Result, Buffer, Length(Buffer));
    Result := Trim (Result);
end;

function ExecuteFile(const FileName, Params, DefaultDir: string; ShowCmd: Integer): THandle;
var
   zFileName, zParams, zDir: array[0..79] of Char;
begin
    Result := ShellExecute(Application.MainForm.Handle, nil,
    StrPCopy(zFileName, FileName), StrPCopy(zParams, Params),
    StrPCopy(zDir, DefaultDir), ShowCmd);
end;



end.
