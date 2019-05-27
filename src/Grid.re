[@bs.module "react-virtualized"] [@react.component]
external make:
    (   ~ref: ReactDOMRe.domRef=?, ~columnCount: int, ~columnWidth: int => int,
        ~rowCount: int, ~rowHeight: int, ~height: int, ~width: int,
        ~cellRenderer: Js.Json.t => React.element, unit
    ) => React.element = "Grid";

[@decco]
type cellInfo = {
    columnIndex: int,
    isScrolling: bool,
    isVisible: bool,
    key: string,
    rowIndex: int,
    style: [@decco.codec Decco.Codecs.magic] ReactDOMRe.style
};

[@bs.val "Object.assign"]
external objAssign : Js.Dict.t(_) => ReactDOMRe.style => ReactDOMRe.style = "";

let cellRendererWrapper = (cellRenderer, json) => {
    let { style } as cellInfo =
        cellInfo_decode(json)
        |> Belt.Result.getExn;

    cellRenderer({
        ...cellInfo,
        style: objAssign(Js.Dict.empty(), style)
    });
};

let makeProps =
    (~ref=?, ~height, ~width, ~columnCount, ~columnWidth, ~rowCount, ~rowHeight,
        ~cellRenderer, ())
    =>
        makeProps(
            ~ref?, ~height, ~width, ~columnCount, ~columnWidth, ~rowCount, ~rowHeight,
            ~cellRenderer=cellRendererWrapper(cellRenderer),
            ()
        );
