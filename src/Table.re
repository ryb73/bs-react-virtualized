open Belt.Option;

[@bs.module "react-virtualized"] [@react.component]
external make:
    (   ~className: string=?,
        ~onRowClick: (Js.Json.t => unit)=?,
        ~onRowDoubleClick: (Js.Json.t => unit)=?,
        ~onRowMouseOut: (Js.Json.t => unit)=?,
        ~onRowMouseOver: (Js.Json.t => unit)=?,
        ~onRowRightClick: (Js.Json.t => unit)=?,
        ~rowClassName: (Js.Json.t => string)=?,
        ~headerHeight: int,
        ~height: int,
        ~rowCount: int,
        ~rowGetter: Js.Json.t => Js.Dict.t(string),
        ~rowHeight: int,
        ~width: int,
        ~children: 'a,
        unit
    ) => React.element = "Table";

[@decco] type rowIndex = { index: int };

let makeRowCallback = (callback, json) =>
    rowIndex_decode(json)
    |> Belt.Result.getExn
    |> callback;

let mouseEvent = (callback, json) =>
    TableEvent.t_decode(json)
    |> Belt.Result.getExn
    |> callback;

let makeProps =
    (~height, ~width, ~headerHeight, ~rowCount, ~rowHeight, ~rowGetter, ~rowClassName=?,
        ~onRowClick=?, ~onRowDoubleClick=?, ~onRowMouseOut=?, ~onRowMouseOver=?,
        ~onRowRightClick=?, ~className=?, ~children, ()) =>
{
    makeProps(
        ~className?,
        ~headerHeight,
        ~height,
        ~onRowClick=?map(onRowClick, mouseEvent),
        ~onRowDoubleClick=?map(onRowDoubleClick, mouseEvent),
        ~onRowMouseOut=?map(onRowMouseOut, mouseEvent),
        ~onRowMouseOver=?map(onRowMouseOver, mouseEvent),
        ~onRowRightClick=?map(onRowRightClick, mouseEvent),
        ~rowClassName=?map(rowClassName, makeRowCallback),
        ~rowCount,
        ~rowGetter=makeRowCallback(rowGetter),
        ~rowHeight,
        ~width,
        ~children,
        ()
    );
};
