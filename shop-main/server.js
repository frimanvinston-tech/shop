import express from 'express'
import fs from 'fs'
import multer from 'multer'
const mount = express()

const upload = multer({dest: 'public/images'})

mount.set('view engine', 'ejs')
mount.use(express.static('public'))
mount.use(express.urlencoded({extended: true}))

mount.get('/', (req, res) =>{
    res.render("index", {
        mount: 'in another life',      
        cssname: "products"
})
})


mount.get('/products', (req, res) =>{
    const data = fs.readFileSync('data.json','utf-8')
    const myproducts = JSON.parse(data);

    res.render("products", {
        mount: 'in another life',
        products: myproducts,
        cssname: "product"
    })
})

mount.get('/cart', (req,res) =>{
    res.render("cart", {
        mount: 'in another life',      
        cssname: "cart"
    })
})
  mount.get("/products/add",(req, res) => {
        res.render('add-product',{mount: 'in another life',      
        cssname: "product",})      
    })

    mount.post('/products/add',upload.single('image'), (req, res) => {
        const data = fs.readFileSync('data.json', 'utf-8' )
        const product = JSON.parse(data)

        const newProd = {
            id: product.length > 0 ? product.length + 1 : 1,
            name: req.body.name,
            price: Number(req.body.price),
            image: '/image/' + req.file/filename + req.file.originalname
        }
        product.push(newProd)
        fs.writeFileSync('data.json', JSON.stringify(product, null, 2))

        res.redirect('/products')
    })



mount.listen(5700)