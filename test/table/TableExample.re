[@bs.module] external data : array(Js.Dict.t(string)) = "../../../../test/table/data";

let rowGetter = ({ Table.index }) => data[index];

ReactDOMRe.renderToElementWithId(
    <Table height=500 width=500 rowHeight=20 headerHeight=20 rowGetter
           rowCount=Js.Array.length(data)
    >
        <Column dataKey="artist" width=0 flexGrow=1 label="Artist" />
        <Column dataKey="track" width=0 flexGrow=1 label="Track" />
    </Table>
    ,
    "container"
);
