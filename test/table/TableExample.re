[@bs.module] external data : array(Js.Dict.t(string)) = "../../../../test/table/data";

[%bs.raw {|require("react-virtualized/styles.css")|}];

let rowGetter = ({ Table.index }) => data[index];

ReactDOMRe.renderToElementWithId(
    <AutoSizer>
        (({ width, height }) =>
            <Table height width rowHeight=20 headerHeight=20 rowGetter
                rowCount=Js.Array.length(data) onRowClick=Js.log2("click")
            >
                <Column dataKey="artist" width=0 flexGrow=1 label="Artist" />
                <Column dataKey="track" width=0 flexGrow=1 label="Track" />
            </Table>
        )
    </AutoSizer>
    ,
    "container"
);
